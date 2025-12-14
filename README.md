<h4 align="center" style="
  font-size: 28px;
  font-weight: 900;
  color: #ff003c;
  text-shadow: 
      0 0 5px #ff003c,
      0 0 10px #ff003c,
      0 0 20px #ff1744,
      0 0 30px #ff1744,
      0 0 40px #ff1744;
">
  বাংলা ইন্টারপ্রেটার
</h4>

<p align="center">
  <a href="https://banglaprograminglanguageinterpreter.netlify.app/" target="_blank" style="
      display: inline-block;
      transition: transform 0.25s ease, box-shadow 0.25s ease;
  ">
    <img src="https://img.shields.io/badge/🔥 LIVE%20DEMO-FF0000?style=for-the-badge&logo=netlify&logoColor=white"
         style="border-radius: 8px;
                box-shadow: 0 0 10px #ff002b, 0 0 20px #ff002b;">
  </a>
</p>


📌 Bangla Compiler – Project Description
Bangla Compiler হলো একটি কাস্টম ডিজাইন করা প্রোগ্রামিং ভাষার কম্পাইলার, যা বাংলা কীওয়ার্ড ব্যবহার করে C-style প্রোগ্রামিংকে সহজ-বোধ্য ভাবে উপস্থাপন করে। এই প্রকল্পটি মূলত Compiler Design কোর্সের শিক্ষাগত প্রয়োজনে তৈরি, যেখানে লেক্সিক্যাল অ্যানালিসিস, সিনট্যাক্স অ্যানালিসিস, পার্স ট্রি, ইন্টারপ্রেটেশন, এবং কোড এক্সিকিউশনের মতো মূল ধারণাগুলো বাস্তবে প্রয়োগ করা হয়েছে।

🎯 Project Goal
বাংলা ভাষাভিত্তিক একটি সহজ প্রোগ্রামিং ভাষা তৈরি করা
বাংলা কীওয়ার্ড ব্যবহার করে শিক্ষার্থীদের প্রোগ্রামিং শেখা সহজ করা
সম্পূর্ণ কম্পাইলার প্রক্রিয়া (Lex → Parse → Execute) ইমপ্লিমেন্ট করা
নিজস্ব টোকেন, অপারেটর, সিনট্যাক্স রুলস তৈরি করা
CLI-based একটি ইন্টারপ্রেটার/কম্পাইলার তৈরি করা

✨ Features
✔ বাংলা কীওয়ার্ড
নিচের মতো বাংলা শব্দগুলো ব্যবহার করে কোড লেখা যায়:
সংখ্যা → int
অক্ষর → char
যাবত → for / while
যদি / নাহলে → if / else
লিখ → print
নাও → input

✔ Full Lexical Analysis
Identifiers
Numbers
Keywords
Operators (+ – * / %)
Assignment (=)
Comparison (== < > <= >=)
Whitespace এবং newline handling
✔ Syntax Analysis (Custom Parser)
Variable declaration
Expression evaluation
Condition handling (if-else)
Loop execution
Scope management

✔ Interpreter / Executor
Parse tree অনুসারে স্টেটমেন্ট execute
Variable table / symbol table
Loop & condition execution
Built-in I/O (input-output)

✔ Error Handling
Unknown token
Missing semicolon
Unexpected keyword
Undefined variable
Type mismatch

🧩 Example Bangla Code (Your BD Script Language)
সংখ্যা n
লিখ "n এর মান দিন: "
নাও n

সংখ্যা fact 1

যাবত i = 1 থেকে i <= n পর্যন্ত
    fact = fact * i
শেষ

লিখ n "! = " লিখ fact

Output:
5! = 120


📐 Compiler Architecture
Source Code
     ↓
Lexical Analyzer (Tokenizer)
     ↓
Syntax Parser
     ↓
Abstract Syntax Tree (AST)
     ↓
Interpreter / Executor
     ↓
Output


🛠 Technologies Used
C Language (Core compiler logic)
Flex/Bison (optional) অথবা Manual Lexer/Parser
Windows/Linux CLI
File system for script execution

📁 Deliverables
Bangla Compiler source code
Executable (CLI-based)
Sample BD Script programs
Project report + documentation
Demo video / screenshots (optional)

🏁 Conclusion
এই Bangla Compiler প্রকল্পটি বাংলা ভাষায় প্রোগ্রামিংয়ের একটি নতুন সম্ভাবনা তৈরি করে। পাশাপাশি, Compiler Design-এর বাস্তব জ্ঞান — যেমন tokenizing, parsing, AST, এবং interpretation — ব্যবহার করে একটি কার্যকরী মিনিমাল প্রোগ্রামিং ভাষা তৈরির পুরো প্রক্রিয়াটি শেখায়।
