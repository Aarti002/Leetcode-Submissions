class StreamChecker {
public:
    struct TreeNode{
        vector<TreeNode *> nodes;
        bool isword;
        TreeNode(){
            nodes = vector<TreeNode *>(26,NULL);
            isword = false;
        }
    };

    TreeNode *root;
    string build;

    void insert(vector<string>& words)
    {
        for(string &s : words)
        {
            reverse(s.begin(),s.end());
            TreeNode *temp = root;
            for(char c : s)
            {
                if(!temp->nodes[c-'a']) temp->nodes[c-'a'] = new TreeNode();
                temp = temp->nodes[c-'a'];
            }
            temp->isword = true;
        }
    }

    StreamChecker(vector<string>& words) {
        root = new TreeNode();
        build = "";
        insert(words);
    }

    bool query(char letter) {
        build += letter;
        TreeNode *temp = root;
        for(int i=build.size()-1; i>=0 && temp; i--)
        {
            temp = temp->nodes[build[i]-'a'];
            if(temp && temp->isword)
            {
                return true;
            }
        }
        return false;
    }
};