#include "feedback_struct.h"

void submitFeedback(const string& userEmail, vector<Feedback>& feedbacks);
void displayFeedbacks(const vector<Feedback>& feedbacks);
string censorEmail(const string& email);