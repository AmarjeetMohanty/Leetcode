class Solution {
public:
    int performOperation(string operation, int firstNumber, int secondNumber) {
        if(operation == "+")
            return secondNumber + firstNumber; 
        if(operation == "-")    
            return secondNumber - firstNumber; 
        if(operation == "*")
            return secondNumber * firstNumber; 
        return secondNumber / firstNumber; 
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> tokenStack;
        set<string> operators = {"+", "-", "*", "/"};

        for(int i = 0; i < tokens.size(); i++)
        {
            // if the token is an operator 
            if(operators.find(tokens[i]) != operators.end())
            {
                // pop the 2 numbers in the stack 
                int firstNumber = tokenStack.top();
                tokenStack.pop();
                int secondNumber = tokenStack.top(); 
                tokenStack.pop();

                // do the operation on the two numbers
                int operationResult = performOperation(tokens[i], firstNumber, secondNumber); 

                // push the result of the operation in the stack 
                tokenStack.push(operationResult); 
            }
            else
            {
                // if the token is a number, push it to the stack
                tokenStack.push(stoi(tokens[i])); 
            }
        }
        return tokenStack.top();
    }
};