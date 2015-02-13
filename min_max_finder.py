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

def convert_to_string(array):
    return re.sub('[(),]', '', str(array))

def get_min_max(num_args):
    """
    Find the largest MAX_DEPTH needed to solve a push_swap given any input of num_args arguments
    """
    args = [i for i in range(num_args)]
    permutations = itertools.permutations(args)
    max_solution_length = 0;
    for perm in permutations:
        cmd = './push_swap ' + convert_to_string(perm);
#        print("cmd = " + str(cmd));
        exitcode, out, err = get_exitcode_stdout_stderr(cmd)
        length = out.count(' ') + 1
        print('calling "' + cmd + '" and getting length = ' + str(length) + '\t' + out[:-1])
        if length > max_solution_length:
            max_solution_length = length
    return max_solution_length
        

for i in range(10):
    print('given ' + str(i) + ' arguments, the largest MAX_DEPTH needed is ' + str(get_min_max(i)))
