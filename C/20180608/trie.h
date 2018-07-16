#ifndef _TRIE_TREE_H_
#define _TRIE_TREE_H_

#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include <iostream>

/* 
* 
* 
*/
class TrieTree
{
  public:
    static const int MAX_BRANCH_SIZE = 26;

    // tree node
    typedef struct tagTireNode
    {
        tagTireNode *child[MAX_BRANCH_SIZE];
        int leafFlag;

        tagTireNode() : leafFlag(-1)
        {
            memset(child, 0x00, sizeof(child));
        }

    } TrieNode, *pTireNode;

    TrieTree() : m_root(new TrieNode), m_count(0)
    {
    }

    ~TrieTree()
    {
        Clear();
    }

    /* 
    * Clear all node 
    * 
    */
    void Clear()
    {
        Clear(m_root);
    }

    /* 
    * search string  
    * 
    */
    bool Search(const char *word)
    {
        pTireNode cur = m_root;
        size_t depth = strlen(word);

        for (size_t i = 0; i < depth; i++)
        {
            int idx = CharToIndex(word[i]);
            if (!cur->child[idx])
            {
                return false;
            }

            cur = cur->child[idx];
        }

        return cur;
    }

    /* 
    * Insert string to tree 
    * 
    */
    void Insert(const char *word)
    {
        pTireNode cur = m_root;
        size_t depth = strlen(word);
        for (size_t i = 0; i < depth; i++)
        {
            int idx = CharToIndex(word[i]);
            if (!cur->child[idx])
            {
                if (0 == i)
                    m_count++;

                cur->child[idx] = new TrieNode;
            }

            cur = cur->child[idx];
        }

        cur->leafFlag = 0;
    }

    /* 
    * Compress output tree 
    * 
    */
    void OuputCompressTree(std::string &output)
    {
        OuputCompressTree(output, m_root);
    }

  private:
    void OuputCompressTree(std::string &output, pTireNode root)
    {
        for (size_t i = 0; i < MAX_BRANCH_SIZE; i++)
        {
            if (root->child[i])
            {
                char c = IndexToChar(i);
                output += c;

                if (0 == root->leafFlag)
                {
                    return;
                }
                else
                {
                    OuputCompressTree(output, root->child[i]);
                }
            }
        }
    }

    /* 
    * 
    * 
    */
    void Clear(pTireNode &node)
    {
        if (0 == node)
            return;

        for (size_t i = 0; i < MAX_BRANCH_SIZE; i++)
        {
            Clear(node->child[i]);
        }

        delete node;
        node = 0;
    }

    /* 
    * 
    * 
    */
    int CharToIndex(char input)
    {
        return (int)(input - 'a');
    }

    /* 
    * 
    * 
    */
    char IndexToChar(int idx)
    {
        return (char)(idx + 'a');
    }

  private:
    pTireNode m_root;
    size_t m_count;
};

/* 
* Test interface 
* 
*/
void TestTrieTree()
{
    char *words[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "ant", "these", "heap",
                     "dynamic", "day", "micro", "meter", "mimic", "soul", "such", "many", "metal"};
    size_t size = sizeof(words) / sizeof(words[0]);

    TrieTree tree;
    for (int i = 0; i < size; i++)
    {
        tree.Insert(words[i]);
    }

    for (int i = 0; i < size; i++)
    {
        assert(tree.Search(words[i]));
    }

    assert(tree.Search("man"));
    assert(tree.Search("met"));
    assert(tree.Search("so"));
    assert(!tree.Search("bee"));
    assert(!tree.Search("at"));

    std::string outputBuf;
    tree.OuputCompressTree(outputBuf);
    std::cout << outputBuf.c_str() << std::endl;
}

#endif