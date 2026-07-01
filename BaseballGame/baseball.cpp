#include<stdexcept>
#include<string>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		assertInvalidException(guessNumber);
	}

private:
	void assertInvalidException(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (auto ch : guessNumber) {
			if (ch < '0' || ch > '9') {
				throw invalid_argument("must be number");
			}
		}

		for (int i = 0; i < guessNumber.length(); i++) {
			for (int j = i + 1; j < guessNumber.length(); j++) {
				if (guessNumber[i] == guessNumber[j]) {
					throw invalid_argument("must not have duplicate numbers");
				}
			}
		}
	}
};
