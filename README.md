# Sentement_Classification_from_text_in_C

# Goal: 
In this project, you’ll implement a simple AI classifier that can determine a sentence belongs to
which sentiment. This will reinforce and teach you the basics of Artificial Intelligence. This project is
designed to be completed from scratch using only the utilities provided by core C language. You are
free to use whatever we read in class if you are comfortable doing so.
# Introduction:
The process of computationally identifying and categorizing opinions expressed in a piece of text,
especially in order to determine whether the writer's attitude towards a particular topic, product,
etc., is positive, negative, or neutral.
Provided material:
You are provided two text files that contains a list of positive, negative words respectively. You have
to assign sentiment on the basis of maximum matching. i.e. if maximum words of sentence are from
positive words then assign it positive sentiment. If positive and negative words in a sentence are
same then it belongs to neutral sentence.
Your program must perform some steps:
# Preprocessing:
Write a function that accepts a string sentence and:
• replaces all punctuation with spaces,
• converts the input string to lower case,
• splits the string to words
• and removes stop-words.
Assign sentiment to sentence by maximum matching of positive and negative words.
# Implementation help:
Step 1: Define arrays such as positivewords [], negativewords [] and neutralwords [].
Step 2: Input the sentence.
Step 3: For each word in sentence, compare with happywords [], sadwords [] and angrywords [].
If the words are present in positivewords [] then increment positivesentiment.
If the words are present in negativewords [] then increment negativesentiment.
If the words are present in neutralwords [] then increment neutralsentiment.

The project is to use the provided data to develop an algorithm that will allow a user to input a new
review and will automatically score the sentiment of the review.

# Example output:
enter a review -- Press return to exit:
A weak script that ends with a quick and boring finale
Negative Sentiment
enter a review -- Press return to exit:
Loved every minute of it
Positive Sentiment
