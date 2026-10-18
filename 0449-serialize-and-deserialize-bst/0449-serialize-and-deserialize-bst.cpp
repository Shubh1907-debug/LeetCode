#include <string>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

class Codec {
public:
    void preorder(TreeNode* node, string& data) {
        if (!node) return;
        if (!data.empty()) data += ',';
        data += to_string(node->val);
        preorder(node->left, data);
        preorder(node->right, data);
    }

    string serialize(TreeNode* root) {
        string data;
        preorder(root, data);
        return data;
    }

    TreeNode* build(const vector<int>& values, int& index,
                    long long lower, long long upper) {
        if (index == values.size()) return nullptr;

        int value = values[index];
        if (value <= lower || value >= upper) return nullptr;

        ++index;
        TreeNode* node = new TreeNode(value);
        node->left = build(values, index, lower, value);
        node->right = build(values, index, value, upper);
        return node;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<int> values;
        stringstream stream(data);
        string token;

        while (getline(stream, token, ',')) {
            values.push_back(stoi(token));
        }

        int index = 0;
        return build(values, index, LLONG_MIN, LLONG_MAX);
    }
};