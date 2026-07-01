#include<stdexcept>
#include<string>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& question) : question(question) {}

	GuessResult guess(const string& guessNumber) {
		assertInvalidException(guessNumber);

		int strikes = 0;
		int balls = 0;

		for (int i = 0; i < guessNumber.length(); i++) {
			if (guessNumber[i] == question[i]) {
				strikes++;
			}
			else if (question.find(guessNumber[i]) != string::npos) {
				balls++;
			}
		}

		return GuessResult{ guessNumber == question, strikes, balls };
	}

private:
	string question;

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
