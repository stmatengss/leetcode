

class Solution {

	public:
		int lengthOfLastWord(string s) {

			int counter = 0;
			int i;
			for (i = s.length() - 1; i >= 0; i -- ) {

				if (s[i] != ' ')
					break;
			}
			for (; i >= 0; i -- ) {

				if (s[i] == ' ')
					break;
				counter ++;

			}
			return counter;
		}
}
