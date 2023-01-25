#include<iostream>
#include<string>
using namespace std;
struct Node
{
    Node * links [26];
    int count_startsWith=0;
    int count_startPrefix=0;
    bool ContainsKey(char ch)
    {
        return (links[ch-'a']!=nullptr);
    }
    void put(char ch, Node * node)
    {
        links[ch='a'] = node;
    }
    Node * get(char ch)
    {
        return links[ch-'a'];
    }
    void increaseEnd()
    {
        count_startsWith++;
    }
    void increasePrefix()
    {
        count_startPrefix++;
    }
    void decreaseEnd()
    {
        count_startsWith--;
    } 
    void decreasePrefix()
    {
        count_startPrefix--;
    }
    int getEnd()
    {
        return count_startsWith;
    }
    int getPrefix()
    {
        return count_startPrefix;
    }
};
class Trie
{
    private: Node * root;
    public:
    Trie()
    {
            root = new Node();
    }
    void insert(string word)
    {
        Node * node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->ContainsKey(word[i]))
            {
               node->put(word[i],new Node());
            }
            node = node->get(word[i]);
             node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(string &word)
    {
        Node * node = root;
        for(int i=0;i<word.size();i++)
        {
             if(!node->ContainsKey(word[i])) return 0;
             node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;

        for(int i=0;i<word.size();i++)
        {
            if(!node->ContainsKey(word[i])) return 0;
            node = node->get(word[i]);
        }

        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node * node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->ContainsKey(word[i])) return;
            node=node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};

int main()
{
   Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}