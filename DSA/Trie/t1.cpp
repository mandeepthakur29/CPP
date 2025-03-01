#include <iostream>

// Class representing a single node in the Trie
class TrieNode
{
    public:
        char data;                  // The character stored in the node
        TrieNode* children[26];     // Array of pointers to children nodes (26 for each letter of the alphabet)
        bool isEnd;            // Flag to check if the node marks the end of a word

        // Constructor to initialize a TrieNode
        TrieNode(char ch)
        {
            data = ch;              // Assign the character to the node
            // Initialize all children pointers to NULL
            for(int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isEnd = false;     // Initially, the node is not terminal (not the end of a word)
        }
};

// Class representing the entire Trie
class Trie{
    public:
        TrieNode* root;             // Pointer to the root node of the Trie

        // Constructor to initialize the Trie
        Trie(){
            root = new TrieNode('\0');  // Root node with a null character as it doesn’t represent any letter
        }

        // Helper function to recursively insert a word into the Trie
        void insertUtil(TrieNode* root, std::string word)
        {
            // Base case: If the word is empty, mark the current node as terminal
            if(word.length() == 0){
                root->isEnd = true;
                return;
            }

            // Assuming the word is in uppercase letters, calculate the index for the first character
            int index = word[0] - 'A';
            TrieNode* child;

            // If the child node for this character already exists
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                // If the child node for this character does not exist, create a new node
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // Recursively insert the remaining part of the word into the Trie
            insertUtil(child, word.substr(1));
        }

        // Function to insert a word into the Trie
        void insertWord(std::string word)
        {
            // Call the recursive utility function starting from the root
            insertUtil(root, word);
        }

        bool searchWord(std::string word){
            return searchUtil(root, word);
        }

        bool searchUtil(TrieNode* root, std::string word){
            //base case
            if(word.length() == 0){
                return root->isEnd;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                return false;
            }

            return searchUtil(child, word.substr(1));
        }
};

int main()
{
    Trie *t = new Trie();  // Create a new Trie object

    t->insertWord("TIME"); // Insert the word "abcd" into the Trie
    t->insertWord("TERA");
    t->insertWord("WEEB");

    std::cout<< t->searchWord("TIM")<<std::endl;;

    return 0;
}
