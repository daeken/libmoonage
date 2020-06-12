using System.Linq;
using System.Text;

namespace Arch {
	public class CodeBuilder {
		readonly StringBuilder Builder = new StringBuilder();
		public string Code => Builder.ToString();
		int Indent;

		public static CodeBuilder operator +(CodeBuilder left, int depth) {
			left.Indent += depth;
			return left;
		}
		public static CodeBuilder operator -(CodeBuilder left, int depth) {
			left.Indent -= depth;
			return left;
		}

		public static CodeBuilder operator ++(CodeBuilder left) {
			left.Indent++;
			return left;
		}
		public static CodeBuilder operator --(CodeBuilder left) {
			left.Indent--;
			return left;
		}

		public static CodeBuilder operator +(CodeBuilder left, string data) {
			if(data.Contains("\n"))
				return data.Split('\n').Aggregate(left, (current, line) => current + line);
			left.Builder.Append(new string('\t', left.Indent) + data + "\n");
			return left;
		}
	}
}