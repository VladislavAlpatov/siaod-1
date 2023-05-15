#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class TreeNode
{
public:
	std::unordered_map<char, TreeNode*> m_vecChildren;
	bool m_bIsTerminal = false;

	TreeNode() = default;
};

class Trie
{
public:
	TreeNode* m_pRootNode;

	Trie()
	{
		m_pRootNode = new TreeNode();
	}

	void insert(const std::string& word) const
	{
		TreeNode* pNode = m_pRootNode;
		for (char c : word)
		{
			if (pNode->m_vecChildren.find(c) == pNode->m_vecChildren.end())
			{
				pNode->m_vecChildren[c] = new TreeNode();
			}
			pNode = pNode->m_vecChildren[c];
		}
		pNode->m_bIsTerminal = true;
	}
};

std::vector<std::pair<size_t, size_t> > search_patterns(std::vector<std::string>& patterns,const std::string& text)
{
	Trie trie;
	for (const auto& pattern : patterns)
		trie.insert(pattern);


	std::vector<std::pair<size_t, size_t> > matches;
	for (size_t i = 0; i < text.size(); i++)
	{
		TreeNode* node = trie.m_pRootNode;
		for (size_t j = i; j < text.size(); j++)
		{
			char c = text[j];
			if (node->m_vecChildren.find(c) == node->m_vecChildren.end())
			{
				break;
			}
			node = node->m_vecChildren[c];
			if (node->m_bIsTerminal)
			{
				matches.emplace_back(i, j);
			}
		}
	}
	return matches;
}

int main()
{
	std::vector<std::string> patterns{"lore", "full"};
	std::string text = "goofy ahh quandale dingle full lore goofy ahh";
	std::vector<std::pair<size_t , size_t> > matches = search_patterns(patterns, text);

	for (auto match : matches)
		std::cout << "Match found at index " << match.first << "-" << match.second << "\n";

	return 0;
}