# HackerRank Test Case Generator

Generate test cases for your problem easily. Credits to @aashutoshrathi.

## Table of Contents

- [1. Getting Started](#1-getting-started)
  - [1.1. Identify your Input Format and Constraints](#11-identify-your-input-format-and-constraints)
  - [1.2. Your Solution Algorithm](#12-your-solution-algorithm)
  - [1.3. Define Input Format](#13-define-input-format)
    - [1.3.1. Required Information for TestGenerator](#131-required-information-for-testgenerator)
  - [1.4. Find the Zipped Test Files](#14-find-the-zipped-test-files)
- [2. Contributions](#2-contributions)

## 1. Getting Started

For the example lets take the simple problem "[Clock Delay](https://www.hackerrank.com/contests/hourrank-28/challenges/clock-delay)" as the problem you have created.

### 1.1. Identify your Input Format and Constraints

> #### Input Format
> - The first line contains ***q***, the number of queries.
> - Each query is described by two lines. The first line contains four space-separated integers ***h1, m1, h2, m2***. The second line contains a single integer ***k***.

> #### Constraints
> - 1 ≤ ***q*** ≤ 1000
> - 0 ≤ ***h1*** < 23
> - 0 ≤ ***h2*** < 24
> - 0 ≤ ***m1***, ***m2*** < 60
> - 1 ≤ ***k***
> - ***h1*** + ***k*** < 24
> - It is guaranteed that ***h1:m1*** is strictly before ***h2:m2***

### 1.2. Your Solution Algorithm

This can be python, java, c++, c file. If you need support other languages please update the `Language` class in the [TestGenerator.py](src/TestGenerator.py) file.

1. Your solution [Logic.py](src/example/Logic.py) file. 

```py
q = int(input())

for i in range(q):
    h1, m1, h2, m2 = map(int, input().split())
    k = int(input())
    delay = (h1 + k - h2) * 60 + m1 - m2
    print(delay)
```

2. Your solution [Logic.java](src/example/Logic.java) file.

```java
import java.util.Scanner;

public class Logic {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();

        for (int i = 0; i < q; i++) {
            int h1, m1, h2, m2, k;
            h1 = scanner.nextInt();
            m1 = scanner.nextInt();
            h2 = scanner.nextInt();
            m2 = scanner.nextInt();
            k = scanner.nextInt();

            int delay = (h1 + k - h2) * 60 + m1 - m2;
            System.out.println(delay);
        }
    }
}
```

### 1.3. Define Input Format

Create a file [ClockDelayInputFormat.py](src/example/ClockDelayInputFormat.py) in the same directory the [Logic.py](src/example/Logic.py) file contains.

Create the class `ClockDelayInputFormat` extending `TestInputFormat` and overriding `inputs(difficult_level)` method with constraints and input format identified in the second step.

You can introduce difficulty with using `difficult_level` value which is between $0$ and 9 inclusively [0-9].

```py
import random

from TestGenerator import TestGenerator, TestInputFormat, Language


# Problem https://www.hackerrank.com/contests/hourrank-28/challenges/clock-delay
class ClockDelayInputFormat(TestInputFormat):
    # difficulty levels with test file number
    # difficulty level is [0-9]
    diff = [(5, 10), (10, 30), (50, 100), (100, 300), (100, 300),
            (300, 600), (600, 900), (800, 1000), (900, 1000), (950, 1000)]

    def inputs(self, difficult_level):
        q = random.randint(*self.diff[difficult_level])  # number of test cases
        print(q)
        for n in range(q):
            # constraints for h1 m1 h2 m2 k
            h1 = random.randint(0, 23)
            m1 = random.randint(0, 60)
            h2 = random.randint(h1, 24)
            k = random.randint(h2 - h1 + 1 if h1 == h2 else h2 - h1, 24 - h1)
            m2 = random.randint(0, (m1 if h1 + k == h2 else 60))
            print(h1, m1, h2, m2)
            print(k)


inputFormat = ClockDelayInputFormat()

# try with Language.java('Logic') also
test_generator = TestGenerator(10, inputFormat, Language.python('Logic'), "ClockDelay")
test_generator.run()
```

Create instance `inputFormat` of `ClockDelayInputFormat` class. Create generator using `TestGenerator` class with required information.

#### 1.3.1. Required Information for TestGenerator

- Number of Test Files Needs: ***10***
- Instance of TestInputFormat: ***ClockDelayInputFormat***
- Language of Solution File (python, java, c++, c) and File Name: ***python(Logic)*** also try with ***java(Logic)***
- Name of the Problem: ***ClockDelay***

### 1.4. Find the Zipped Test Files

See the directory the [Logic.py](src/example/Logic.py) file contains with the name `${Name}-test-cases.zip`.

## 2. Contributions

Contributions are welcome! :)