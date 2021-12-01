using System;
using System.Collections.Generic;
using System.IO;

namespace day1 {
    class Program {
        const int WINDOW_SIZE = 3;
        static void Main(string[] args) {
            int count = 0, curr;
            List<int> prevs = new List<int>() { 0 };
            using (StreamReader sr = new StreamReader("day1.txt")) {
                while (!sr.EndOfStream) {
                    curr = int.Parse(sr.ReadLine());
                    prevs.Add(prevs[prevs.Count - 1] + curr);
                }
                for (int i = WINDOW_SIZE + 1; i < prevs.Count; ++i) {
                    if ((prevs[i] - prevs[i - WINDOW_SIZE]) > (prevs[i - 1] - prevs[i - (WINDOW_SIZE + 1)])) {
                        ++count;
                    }
                }
            }
            Console.WriteLine($"{count}");
        }
    }
}
