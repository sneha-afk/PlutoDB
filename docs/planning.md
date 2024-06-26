# planning

But first, there was a plan.

---

## purpose

A simple DBMS with an easy user CLI and efficient data representation.

## structure

* `main.cpp`: running loop of the program, continuously takes in user input and directs to appropriate handler

TBD

## features

TBD

## goals

### overall
- [ ] Effective serialization/deserialization from file
- [ ] Tokenized user input in CLI
- [ ] Efficient lookups and insertions into individual tables

### reach
- [ ] Referential integrity to other tables
- [ ] Complex constraints such as CHECK
- [ ] Batch query execution
- [ ] User credentials and encryption of data
- [ ] Research: optimization techniques

### baseline
- [ ] CREATE/INSERT/SELECT statements
- [ ] Persistence across program calls
- [ ] Schema validation within table constraints
- [ ] Linear lookups, constant inserts

---
## dev journal


### June 25, 2024

origin. motivation: rdbms are cool, and i should practice c++!

preliminary sequence of features:
* start with CREATE/INSERT/SELECT statements
* naive storage: plain text files in the same directory
* naive data structure: linked list during up-time
