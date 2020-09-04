using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;
using MoreLinq;

namespace Arch {
	public class HangChecker : IDisposable {
		static Stopwatch Stopwatch = Stopwatch.StartNew();
		static readonly ConcurrentDictionary<HangChecker, HangChecker> All =
			new ConcurrentDictionary<HangChecker, HangChecker>();

		readonly string Name;
		long Start;

		public HangChecker(string name) {
			Name = name;
			All[this] = this;
			Reset();
		}

		public void Reset() => Start = Stopwatch.ElapsedMilliseconds;

		public void Dispose() => All.Remove(this, out var _);

		public static T Check<T>(string name, Func<T> cb) {
			using var hc = new HangChecker(name);
			return cb();
		}

		public static void Run() =>
			new Thread(() => {
				while(true) {
					Thread.Sleep(1000);
					try {
						var limit = Stopwatch.ElapsedMilliseconds - 1000;
						foreach(var hc in All.Keys)
							if(hc.Start < limit)
								Console.WriteLine($"Hanging in '{hc.Name}'");
					} catch(Exception e) {
						Console.WriteLine($"HangChecker exception: {e}");
					}
				}
			}).Start();
	}
}