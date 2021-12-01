using System;
using System.IO;

namespace day1 {
    class Program {
        static void Main(string[] args) {
            int prev, curr, count = 0;
            using (StreamReader sr = new StreamReader("day1.txt")) {
                prev = int.Parse(sr.ReadLine());
                while (!sr.EndOfStream) {
                    curr = int.Parse(sr.ReadLine());
                    if (curr > prev) {
                        ++count;
                    }
                    prev = curr;
                }
            }
            Console.WriteLine($"{count}");
        }
    }
}
