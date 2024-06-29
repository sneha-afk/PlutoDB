# planning

But first, there was a plan.

---

## purpose

A simple DBMS with an easy user CLI and efficient data representation.

## structure

* `main.cpp`: running loop of the program, continuously takes in user input and directs to appropriate handler


### memory representation

My vision for PlutoDB is to be a lightweight RDBMS with a functional SQL parser. Tackling single-relation queries and constraints will be the first challenge, then expanding to multirelation links.
* `QueryHandler` that has access to the tables in `DB`
    * Methods to oversee the vector of `Table`s in `DB`
    * Catches catches exceptions thrown from the lower hierarchy
    * Need a more robust lexer, parser, and executor
* `class DB`: overarching class containing data and handlers
* `class Table`: stores the information of a relation including its schema and records
    * Contains a vector of `Record`s since there is a variable amount
    * Methods to insert, update, and delete records with datatype, `UNIQUE`, `PRIMARY KEY`, etc. validation
    * Naive approach first: linear search with corresponding values to find
* `class Record`: a finite row within the relation
    * Contains a map of string field names to `Field`s to retrieve
    * Getter/Setter methods to make updates more straightforward
* `class Field`: segment of a `Record`, an interface for more granular types



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

### June 28, 2024

* Started planning on how to represent the data when in-memory
    * Table -> Record -> Field
    * To consider: how to deal with validating Field datatypes during runtime
* Need a more robust lexer and parser for queries
    * My idea: step aside from this and create a simpler key-value store
    * Build the lexer and parser for an easier use-case to bring into here

### June 27, 2024

* Mapping string for keywords and shell commands to enums
    * Easier to send into respective handlers later on
    * Catches invalid shell commands (slash commands)
* Help menu started, along with some cute ASCII art

### June 26, 2024

* Parsing user input to get tokens
    * Strings that are surrounded by quotes are considered case sensitive
    * Support for slash commands (such as `\q`)
* ex. `SELECT name from "Persons";` is parsed as [`SELECT`, `NAME`, `FROM`, `"Persons"`].
* Started a exception hierarchy, with a custom `std::exception` type called `Plutoception`
    * `PESyntax` for pointing at errors within a user's input


### June 25, 2024

origin. motivation: rdbms are cool, and i should practice c++!

preliminary sequence of features:
* start with CREATE/INSERT/SELECT statements
* naive storage: plain text files in the same directory
* naive data structure: linked list during up-time
