class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        i, N, result = 0, len(words), []
        while i < N:
            oneLine, j, curWidth, positions, spaceNum = [words[i]], i+1, len(words[i]), 0, maxWidth-len(words[i])
            while j<N and curWidth+1+len(words[j])<=maxWidth:
                oneLine.append(words[j])
                curWidth+=1+len(words[j])
                spaceNum-=len(words[j])
                positions, j =positions+1, j+1
            i=j
            if i<N and positions:
                spaces = [' ' * (spaceNum//positions + (k< spaceNum%positions)) for k in range(positions)] + ['']
            else:
                spaces = [' ']*positions +[' '*(maxWidth-curWidth)]
            result.append(''.join([s for pair in zip(oneLine, spaces) for s in pair]))
        return result
