# Put this wherever you can call ./push_swap
# call with "python tester.py"

# for capturing output from ./push_swap
import shlex
from subprocess import Popen, PIPE

# creating permutations
import itertools
import re # regular expressions

def get_exitcode_stdout_stderr(cmd):
    """
    Execute the external command and get its exitcode, stdout and stderr.
    """
    args = shlex.split(cmd)
    
    proc = Popen(args, stdout=PIPE, stderr=PIPE)
    out, err = proc.communicate()
    exitcode = proc.returncode
    return exitcode, out, err

def swap(array):
    if (len(array) < 2):
        print('invalid swap')
        exit(1)
    temp = array[0];
    array[0] = array[1]
    array[1] = temp

def push(destination, source):
    if (len(source) == 0):
        print('invalid push')
        exit(1)
    destination = [source[0]] + destination
    source = source[1:]
    return destination, source

def rotate(array):
    if (len(array) < 2):
        print('invalid rotate')
        exit(1)
    array = array[1:] + [array[0]]
    return array

def reverse_rotate(array):
    if (len(array) < 2):
        print('invalid reverse rotate')
        exit(1)
    array = [array[-1]] + array[:-1]
    return array

def perform_operation(first, second, operation):
    if (operation == 'sa'):
        swap(first)
    elif (operation == 'sb'):
        swap(second)
    elif (operation == 'ss'):
        swap(first)
        swap(second)
    elif (operation == 'pa'):
        first, second = push(first, second)
    elif (operation == 'pb'):
        second, first = push(second, first)
    elif (operation == 'ra'):
        first = rotate(first)
    elif (operation == 'rb'):
        second = rotate(second)
    elif (operation == 'rr'):
        first = rotate(first)
        second = rotate(second)
    elif (operation == 'rra'):
        first = reverse_rotate(first)
    elif (operation == 'rrb'):
        second = reverse_rotate(second)
    elif (operation == 'rrr'):
        first = reverse_rotate(first)
        second = reverse_rotate(second)
    else:
        print('invalid operation: |' + str(operation) + '|')
        exit(1)
    return first, second

def is_correct(permutation, output):
    output = output[:-1]
    if (output == "Error"):
        print("oops");
        exit(1);
    output = output.split(" ")
    permutation = list(permutation)
    first = list(permutation)
    second = []
    if not output[0] == '':
        for operation in output:
            first, second = perform_operation(first, second, operation)
    if (len(second)):
        print('length of second after operations is not 0')
        exit(1)
    goodness = True
    for i in range(len(first) - 1):
        if (first[i] > first[i + 1]):
            print('not sorted at end of operations for input: ' + str(list(permutation)) + ' and output ' + str(output))
            goodness = False
            break
    if (goodness):
        print('good: ' + str(list(permutation)))
    return (output.count(" "))

def convert_permutation_to_arguments(array):
    return re.sub('[(),]', '', str(array))

def tester_num_arguments(num_args):
    """
    tests push_swap for all possible inputs with num_args arguments
    """
    for permutation in itertools.permutations([i for i in range(num_args)]):
        cmd = './push_swap ' + convert_permutation_to_arguments(permutation);
        exitcode, out, err = get_exitcode_stdout_stderr(cmd)
        is_correct(permutation, out);
        
# 'main'
for i in range(1, 7):
    tester_num_arguments(i);
