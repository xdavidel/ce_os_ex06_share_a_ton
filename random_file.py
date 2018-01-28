import os
import sys

DEFAULT_OUTPUT_FILE_PATH = "output_file.bin"
TOTAL_FILE_SIZE_IN_GB = 1
SINGLE_WRITE_SIZE = 4 * 1024


def total_file_size_in_bytes(x): return 1024 * 1024 * 1024 * x


def write_random_data_to_file(file_path, size_in_gb=TOTAL_FILE_SIZE_IN_GB):
    print ("Writing random {}GB data to file:".format(size_in_gb, ))
    random_data = os.urandom(SINGLE_WRITE_SIZE)
    loop_size = total_file_size_in_bytes(size_in_gb) / SINGLE_WRITE_SIZE
    with open(file_path, 'wb') as fout:
        for i in range(int(loop_size)):
            fout.write(random_data)
            if i % (loop_size / 50) == 0:
                print ("\r[{}>>".format(("".join(['.' for i in range(int(i / (loop_size / 50)))]))),
                       sys.stdout.flush())
    print ("\b\b\b] Done!")


def main():
    file_path = DEFAULT_OUTPUT_FILE_PATH
    if len(sys.argv) >= 2:
        file_path = sys.argv[1]
    write_random_data_to_file(file_path)


if __name__ == '__main__':
    main()
