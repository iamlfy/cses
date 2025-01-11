#!/usr/bin/env python3
import os
import sys
import shutil
import subprocess
import filecmp
from pathlib import Path

def compile_cpp(cpp_file):
    """编译C++文件"""
    try:
        subprocess.run(['g++-14', '-std=c++11', '-O2', '-Wall', cpp_file, '-o', 'test'], 
                      check=True, capture_output=True)
        return True
    except subprocess.CalledProcessError as e:
        print(f"编译错误：\n{e.stderr.decode()}")
        return False

def run_test(test_input, test_output):
    """运行单个测试用例"""
    try:
        with open(test_input, 'r') as fin:
            result = subprocess.run(['./test'], 
                                  input=fin.read(),
                                  text=True,
                                  capture_output=True,
                                  check=True)
        
        # 规范化实际输出：去除首尾空白并规范化中间空格
        actual_output = ' '.join(result.stdout.strip().split())
        
        # 读取并规范化期望输出
        with open(test_output, 'r') as f:
            expected_output = ' '.join(f.read().strip().split())
        
        # 直接比较规范化后的字符串
        if actual_output != expected_output:
            print(f"测试失败：{test_input}")
            print("预期输出：")
            print(expected_output)
            print("实际输出：")
            print(actual_output)
            return False
        
        return True
    except subprocess.CalledProcessError as e:
        print(f"运行错误：\n{e.stderr}")
        return False

def prepare_tests():
    """准备测试文件"""
    downloads_path = os.path.expanduser("~/Downloads")
    tests_zip = os.path.join(downloads_path, "tests.zip")
    
    # 如果Downloads目录下存在tests.zip
    if os.path.exists(tests_zip):
        print("发现新的测试文件，正在处理...")
        # 删除已存在的tests目录
        if os.path.exists("tests"):
            shutil.rmtree("tests")
        
        # 创建tests目录
        os.makedirs("tests")
        
        # 移动并解压tests.zip到tests目录
        shutil.move(tests_zip, "tests.zip")
        shutil.unpack_archive("tests.zip", "tests")
        os.remove("tests.zip")
        return True
    
    # 如果当前目录下存在tests目录
    if os.path.exists("tests"):
        print("使用当前目录下的测试用例...")
        return True
    
    print("错误：未找到测试文件。请确保存在tests.zip或tests目录。")
    return False

def main():
    if len(sys.argv) != 2:
        print("使用方法：python3 run_tests.py <cpp_file>")
        sys.exit(1)
    
    cpp_file = sys.argv[1]
    
    # 准备测试文件
    if not prepare_tests():
        sys.exit(1)
    
    # 编译程序
    if not compile_cpp(cpp_file):
        sys.exit(1)
    
    # 获取所有测试用例
    test_files = []
    for f in os.listdir("tests"):
        if f.endswith(".in"):
            test_num = f[:-3]
            in_file = os.path.join("tests", f)
            out_file = os.path.join("tests", f"{test_num}.out")
            if os.path.exists(out_file):
                test_files.append((in_file, out_file))
    
    if not test_files:
        print("错误：未找到任何测试用例")
        sys.exit(1)
    
    # 运行测试
    test_files.sort()  # 按文件名排序
    total_tests = len(test_files)
    passed_tests = 0
    
    print(f"开始运行 {total_tests} 个测试用例...")
    for in_file, out_file in test_files:
        test_num = os.path.basename(in_file)[:-3]
        print(f"运行测试 {test_num}...", end=" ")
        if run_test(in_file, out_file):
            print("通过")
            passed_tests += 1
        else:
            print(f"测试终止：{passed_tests}/{total_tests} 个测试通过")
            sys.exit(1)
    
    print(f"\n所有测试通过！({total_tests}/{total_tests})")

if __name__ == "__main__":
    main()