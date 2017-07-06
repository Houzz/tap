'''
Go through all the .php files in test_files directory, and check if the output matches expectation.
'''

from __future__ import print_function
import sys
import os
import glob
import subprocess

CUR_DIR = os.path.dirname(os.path.realpath(__file__))
PHP_DIR = CUR_DIR + "/test_files/"
OUT_DIR = CUR_DIR + "/expected_output/"

EXE_PATH = CUR_DIR + "/../build/tap_server"

def process_php_file(filename):
    output = subprocess.check_output([EXE_PATH, "-m", "single", "-f", filename])
    error_list = []
    for line in output.split('\n'):
        if len(line) > 0 and line[0] == '[':
            print("line: ", line)
            idx = line.index(']')
            err_msg = line[1:idx]
            line = line[idx+1:]
            idx2 = line.index('[')
            line = line[idx2+1:]
            idx3 = line.index(':')
            line_no = line[:idx3]
            error_list.append((int(line_no), err_msg))
    return error_list

def process_expected_output(filename):
    error_list = []
    with open(filename) as f:
        for line in f.readlines():
            line_no, err_msg = line.split()
            error_list.append((int(line_no), err_msg))
    return error_list

def process(php_dir, out_dir):
    for filename in glob.glob(php_dir + "*.php"):
        basename = os.path.basename(filename).split(".")[0]
        exp_filename = out_dir + basename + ".txt"
        print("basename:", basename, "exp_filename:", exp_filename)
        error_list = process_php_file(filename)
        print("error_list:", error_list)
        expected = process_expected_output(exp_filename)
        error_list = sorted(error_list)
        expected = sorted(expected)
        if len(error_list) != len(expected):
            print("TEST FAILED for file", filename)
            print("Expected:", expected)
            print("Actually:", error_list)
            exit(1)
        for i in range(len(error_list)):
            if error_list[i] != expected[i]:
                print("TEST FAILED for file", filename)
                print("Expected:", expected)
                print("Actually:", error_list)
                exit(1)
        print("Test passed for file", filename)
    print("All tests passed.")

if __name__ == '__main__':
    if len(sys.argv) == 3:
        process(sys.argv[1], sys.argv[2])
    else:
        process(PHP_DIR, OUT_DIR)

