import subprocess
import os
import os.path
import signal
from sys import argv
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument("input_file")
parser.add_argument("--id", nargs='?', default="temp")
args = parser.parse_args()

output_dir = os.path.abspath("../Results")
output_dir = os.path.join(output_dir, args.id)
if not os.path.exists(output_dir):
    os.makedirs(output_dir)
output_file = os.path.join(output_dir, os.path.split(args.input_file)[-1])

current_dir = os.path.dirname(os.path.realpath(__file__))

build_path = os.path.abspath(os.path.join("..", "build"))

if not os.path.exists(build_path):
    os.makedirs(build_path)

subprocess.call(["qmake", current_dir], cwd=build_path)
subprocess.call(["make"], cwd=build_path)

subprocess.call(["./test", args.input_file, "multiplication", output_file], cwd=build_path)