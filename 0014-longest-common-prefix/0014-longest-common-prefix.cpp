class TrieNode{
public:
  char data;
  unordered_map<char,TrieNode*>child;
  int count;
  TrieNode(char val){
     data = val;
     count =0;
  }
};

class Solution {
public:
  
  void insertWord(TrieNode* root,string word){
    if(word.size()==0){
        root->count++;
        return;
    }
    char ch = word[0];
    TrieNode* temp;
    if(root->child.find(ch)!=root->child.end()){
           temp = root->child[ch];
    }else{
        temp = new TrieNode(ch);
        root->child[ch]=temp;
        root->count++;
    }
    insertWord(temp,word.substr(1));
  }
 string findLCP(TrieNode* temp,string word){
    string ans ="";
   for(int i =0;i<word.size();i++){
    char ch = word[i];
    if(temp->count==1){
        ans.push_back(ch);
        temp=temp->child[ch];
    }else{
        break;
    }
   }
   return ans;
 }
    string longestCommonPrefix(vector<string>& strs) {
          TrieNode* temp = new TrieNode('-');
        for(int i =0;i<strs.size();i++){
            string t = strs[i];
                insertWord(temp,t);
        }
        return findLCP(temp,strs[0]);
    }
};