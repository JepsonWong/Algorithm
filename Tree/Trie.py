# Trie树的实现，可以用数组，也可以用指针动态分配。
# 在Trie树中主要有3个操作，插入、查找和删除。一般情况下Trie树中很少存在删除单独某个结点的情况，因此只考虑删除整棵树。
# Trie的核心思想是空间换时间。
# https://blog.csdn.net/wsyw126/article/details/61416055

class TrieNode:
	def __init__(self):
		self.R = 26
		self.links = list([0]*self.R)
		self.isEnd = False;

	def containsKey(self, ch):
		return self.links[ord(ch) - ord('a')] != 0

	def get(self, ch):
		return self.links[ord(ch) - ord('a')]

	def put(self, ch, node):
		self.links[ord(ch) - ord('a')] = node

	def setEnd(self):
		self.isEnd = True
	
	def isEnd_(self):
		return self.isEnd

class Trie:

	def __init__(self):
		self.root = TrieNode()

	def insert(self, word):
		node = self.root
        	for i in range(len(word)):
        		currentChar = word[i]
        		if (node.containsKey(currentChar) == False):
        			node.put(currentChar, TrieNode())
        		node = node.get(currentChar)
        	node.setEnd()

	# search a prefix or whole key in trie and
	# returns the node where search ends
	def searchPrefix(self, word):
		node = self.root
		for i in range(len(word)):
        		curLetter = word[i]
        		if (node.containsKey(curLetter)):
        			node = node.get(curLetter)
        		else:
        			return None
        	return node

    	# Returns if the word is in the trie.
    	def search(self, word):
    		node = self.searchPrefix(word);
    		return node != None and node.isEnd_()

    	# Returns if there is any word in the trie
    	# that starts with the given prefix
    	def startsWith(self, prefix):
    		node = self.searchPrefix(prefix);
        	return node != None

def main():
	trie = Trie()
	trie.insert('wangzp')
	trie.insert('zang')
	print trie.search('wangz')
	print trie.search('wang')

main()
