class MagicDictionary:
    def _genNeighbors(self, word):
        for i in range(len(word)):
            yield word[:i]+"*"+word[i+1:]

    def __init__(self):
        """
        Initialize your data structure here.
        """


    def buildDict(self, dict):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: void
        """
        self.words = dict
        self.coll = collections.Counter( nei for word in dict for nei in self._genNeighbors(word))

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        return any( self.coll[nei]>1 or self.coll[nei]==1 and word not in self.words
                        for nei in self._genNeighbors(word))


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)