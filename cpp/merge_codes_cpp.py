#!/usr/bin/env python
# coding: utf-8

import argparse
import os
import re


class Code:
    def __init__(self):
        self.predefined_includes = set()
        self.user_include_names = []
        self.input_contents = []
        self.include_contents = []

    def read_input_file(self, input_file):
        with open(args.input_file) as f, open(args.output_file, 'w') as f_o:
            for line in f:
                match_predefined_include = re.match("#include <", line)
                if match_predefined_include:
                    self.predefined_includes.add(line)
                    continue
                match_user_include = re.match("#include \"(.+?)\.hpp\"", line)
                if match_user_include:
                    self.user_include_names.append(match_user_include.group(1))
                    continue
                self.input_contents.append(line)

    def read_include_file(self, include_name):
        include_files = [include_name + ".hpp", include_name + ".cpp"]
        for include_file in include_files:
            if not os.path.isfile(include_file):
                continue
            with open(include_file) as f:
                for line in f:
                    if re.match("#pragma once", line):
                        continue
                    match_user_include = re.match("#include \"(.+?)\.hpp\"", line)
                    if match_user_include:
                        continue
                    match_predefined_include = re.match("#include <", line)
                    if match_predefined_include:
                        self.predefined_includes.add(line)
                        continue
                    self.include_contents.append(line)

    def read_include_files(self):
        for include_name in self.user_include_names:
            self.read_include_file(include_name)

    def print_code(self, output_file):
        with open(output_file, 'w') as f:
            for line in self.predefined_includes:
                f.write(line)
            for line in self.include_contents:
                f.write(line)
            for line in self.input_contents:
                f.write(line)


def parse_arguments():
    parser = argparse.ArgumentParser(description=' ')
    parser.add_argument('-i', '--input_file', required=True)
    parser.add_argument('-o', '--output_file', default="submit.cpp")
    args = parser.parse_args()
    return args


def main(args):
    code = Code()
    code.read_input_file(args.input_file)
    code.read_include_files()
    code.print_code(args.output_file)


if __name__ == '__main__':
    args = parse_arguments()
    main(args)
