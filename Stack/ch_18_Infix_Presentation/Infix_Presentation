# Is Valid Infix Expressions Presentation (Parenthesis)
## Understanding Infix Expressions
- An **infix expression** is a mathematical notation where operators are placed **between** operands.
- Example: `(4 + a) / c`
- Parentheses `()` are used to **group** sub-expressions and define evaluation order.
- A valid expression must have **balanced** parentheses.

## Checking Parentheses in an Expression
We need to:
1. Count **left** and **right** parentheses.
2. Ensure they **match** in number.
3. Make sure they **close in the correct order**.

## Code Implementation
### Step 1: Count Parentheses

```cpp
for (i = 0; i < expression.length(); i++) {
    currentChar = expression[i];
    if (isLeftParen()) {
        leftParens++;
    }
    if (isRightParen()) {
        rightParens++;
    }
}
if (rightParens != leftParens) return false; // Unbalanced parentheses
```

- Loops through the expression.
- Increments counters for `(` and `)`.
- If the counts **don’t match**, the expression is invalid.

### Step 2: Validating Nested Parentheses

```cpp
if (isLeftParen()) {
    e = "";
    i++;
    currentChar = expression[i];
    parenCounter = 0;
    do {
        if (isLeftParen()) parenCounter++;
        if (isRightParen()) parenCounter--;
        e += expression[i];
        i++;
        currentChar = expression[i];
    } while (!isRightParen() || parenCounter != 0);
    
    if (!isValidExp(e)) return false; // Recursively check inner expression
    operands++; // Treat subexpression as a single operand
}
```

- Extracts the **inner expression** within parentheses.
- Uses `parenCounter` to track nested parentheses.
- Calls `isValidExp(e)` recursively to validate nested expressions.
- Ensures parentheses **close in the correct order**.

---



## Questions?

