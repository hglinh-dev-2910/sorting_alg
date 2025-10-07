- BUILD PROGRAMME WITH FOLLOWING COMMAND-LINE:
    - g++ main.cpp generate.cpp -o a

- RUN 'a.exe' WITH COMMAND-LINE ARGUMENTS AS FOLLOWING SYNTAX FOR GENERATE DATA MODE:
    - ./a linked_list_generate n 
        - linked_list_generate: create data in linked-list mode
        - n: number of elements will be random generate.

    - ./a int_list_generate n 
        - int_list_generate: create data in int mode
        - n: number of elements will be random generate.

- RUN 'a.exe' WITH COMMAND-LINE ARGUMENTS AS FOLLOWING SYNTAX FOR ALGORITHM TESTING MODE: (UPDATE LATER)
    - ./a algo 'algo name' 'filename'
        - algo: enter algorithm mode
        - 'algo name': name of sorting algo(bubble sort, linear sort, etc..)
        - 'filename': name of datafile (.txt or .csv)

    - ./a generate n 'filename'
        - generate: enter generate sample data mode
        - n: number of value need to generate
        - filename: name of datafile to save data

    