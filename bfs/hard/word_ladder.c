/* 
* Problem Statement:
* A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique. 
*/

/*
 * Solution:
 * 1. we construct a trie out of the word list
 * 2. we use BFS approach to check the shortest path, account for the edge case that beginWord == endWord
 * 3. Its simple in concept but takes a lot in execution with many suplementary functions necessary.
 * 4. We need to create the have functions for {struct mapnode, makenode(), freenode(), getleaf(), leaftostring()}
 * 5. Theres also quite a lot of complexity within the main function as well
 */

#define alphabetlength (26)

size_t charToIndex(char c) {
    return (c - 'a');
}

typedef struct Mapnode {
    char c;
    int depth;
    int distance;
    mapnode* parent;
    mapnode* children[alphabetlength];
} Mapnode;

Mapnode* makenode(Mapnode* parent, char c) {
    size_t i = alphabetlength;
    Mapnode* newnode = (Mapode*)malloc(sizeof(Mapnode));
    if (!newnode) return NULL;
    newnode->c = c;
    if (parent) {
        newnode->parent = parent;
        newnode->depth = parent->depth+1;
    } else {
        newnode->parent = NULL;
        newnode->depth = 0;
    }

    newnode->distance = -1;
    memset(newnode->children, 0, sizeof(newnode->children));

    return newnode;
}

void freenode(mapnode* root) {
    size_t i = alphabetlength;
    if (!root) return;
    while (i-->0) {
        freenode(root->children[i]);
    }
    free(root);
}


mapnode* getLeaf(mapnode* root, char* s, int8_t shouldInsert) {
    mapnode* current = root;
    size_t i = 0;
    while (s[i]) {
        if (!current) return 0;
        size_t index = charToIndex(s[i]);
        mapnode* next = current->children[index];
        if (shouldInsert && !next) {
            current->children[index] = makenode(current, s[i]);
            next = current->children[index];
        }
        current = next;
        i++;
    }
    return current;
}


void leafToStr(mapnode* leaf, char* s) {
    s[leaf->depth] = '\0';
    mapnode* current = leaf;
    while (current && current->depth > 0) {
        s[current->depth-1]= current->c;
        current = current->parent;
    }
}


int ladderLength(char* beginWord,char* endWord,char** wordList,int wordListSize) {
 if(wordListSize<=0) {return 0;}
    mapnode* root=makenode(0,'_');
    size_t i=wordListSize;
    while(i-->0)
    {
        getleaf(root,wordList[i],1);
    }
    mapnode* endnode=getleaf(root,endWord,0);
    if(!endnode) {return 0;}
    mapnode* beginnode=getleaf(root,beginWord,1);
    if(beginnode==endnode) {return 1;}
    beginnode->distance=0;
    mapnode** queue=malloc((wordListSize+1)*sizeof(mapnode*));
    queue[0]=beginnode;
    size_t queuefirst=0;
    size_t queuelast=0;
    size_t wordlen=endnode->depth+1;
    char* compareword=malloc((wordlen+1)*sizeof(char));
    int found=0;
    while(queuefirst<=queuelast && !found)
    {
        mapnode* current=queue[queuefirst];
        leaftostr(current,compareword);
        size_t p=0;
        while(p<wordlen && !found)
        {
            char originalc=compareword[p];
            compareword[p]='a';
            while(compareword[p]<='z' && !found)
            {
                mapnode* next=getleaf(root,compareword,0);
                if(next && next->distance<0)
                {
                    int nextdistance=current->distance+1;
                    if(next==endnode)
                    {
                        found=nextdistance;
                        break;
                    }
                    else
                    {
                        next->distance=nextdistance;
                        ++queuelast;
                        queue[queuelast]=next;
                    }
                }
                ++compareword[p];
            }
            compareword[p]=originalc;
            ++p;
        }
        ++queuefirst;
    }
    freenode(root);
    free(queue);
    free(compareword);
    if(found<=0) {return 0;}
    return (found+1);

}
