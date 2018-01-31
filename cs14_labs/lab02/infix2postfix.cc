#include <iostream>
#include <gtest/gtest.h>
#include <stack>
#include <string>

using namespace std;

int priority(char a)
{
  int temp;
  if(a == '*' || a == '/')
  temp = 1;
  else if(a == '+' || a == '-')
  temp = 2;
  return temp;
}

bool isBalancedExpression(string letters)
{
  stack<char> parenthesis;
  for(int i = 0; i < letters.length(); i++)
  {
    if(letters.at(i) == '(' || letters.at(i) == '[' || letters.at(i) == '{')
    parenthesis.push(letters.at(i));
    else if(letters.at(i) == ')' || letters.at(i) == ']' || letters.at(i) == '}')
    {
      if(parenthesis.empty())
      return false;
      else if((parenthesis.top() == '(' && letters.at(i) == ')') || (parenthesis.top() == '[' && letters.at(i) == ']') || (parenthesis.top() == '{' && letters.at(i) == '}'))
      parenthesis.pop();
      else
      return false;
    }
  }
  
  if(parenthesis.empty())
  return true;
  
  return false;
  
}

string infix2postfix(string infix) {
  stack<char> input;
  string temp = "";
  for(int i = 0; i < infix.length(); i++)
  {
    
    if (infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/')
    {
      while(!input.empty() && (priority(input.top()) <= priority(infix.at(i))))
      {
        temp += input.top();
        input.pop();
      }
      input.push(infix.at(i));
      
    }
    
    else if(infix.at(i) == '(')
    input.push(infix.at(i));
    
    else if(infix.at(i) == ')')
    {
      while (input.top() != '(') 
      {
        temp += input.top();
        input.pop();
      }
      input.pop();
      
    }
    
    else
    temp += infix.at(i);
    
  }
    
    while (!input.empty()) 
    {
        temp+= input.top();
        input.pop();
    }

    return temp;
    
    /*if(infix.at(i).isAlpha())
    {
      temp += infix.at(i);
    }
    else if(infix.at(i).isDigit())
    {
      temp+= infix.at(i);
    }
    else if(infix.at(i)== '-' || infix.at(i) == '+' && (input.top() == '*' || infix.top() == "/"))
    {
      temp += infix.at(i);
    }
    
    if(infix.at(i)== ')')
    {
      while(input.top() != '(')
      {
        temp += input.top();
      }
      input.pop();
      
    }
    
  }*/

}

int main() {
  EXPECT_STREQ(infix2postfix("2+3").c_str(), "23+");
  EXPECT_STREQ(infix2postfix("a*b").c_str(), "ab*");
  EXPECT_STREQ(infix2postfix("2+3*5").c_str(), "235*+");
  EXPECT_STREQ(infix2postfix("A+B*C+D").c_str(), "ABC*+D+");
  EXPECT_STREQ(infix2postfix("(A+B)*C-(D-E)*(F+G)").c_str(), "AB+C*DE-FG+*-");
  cout << infix2postfix("(A+B)*C-(D-E)*(F+G)").c_str() << endl;
  EXPECT_EQ(isBalancedExpression("[()["), 0);
  EXPECT_EQ(isBalancedExpression("[(A+B)]{C-D}("), 0);
  EXPECT_EQ(isBalancedExpression("{A-B}{[(A/D)(C-F)](A*E)}"), 1);
  EXPECT_EQ(isBalancedExpression("[(A+B)]{C+D}{[(E+F)(G+H)](I+J)}"), 1);
}

