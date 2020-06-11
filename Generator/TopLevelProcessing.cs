using System;

namespace Generator {
    public class TopLevelProcessing : Builtin {
        public override void Define() {
            Expression("defm", _ => EType.Unit, _ => throw new NotSupportedException()).NoInterpret();
            Expression("def", _ => EType.Unit, _ => throw new NotSupportedException()).NoInterpret();

            Expression("print", list => list[1].Type, list => GenerateExpression(list[1]))
                .Interpret((list, state) => {
                    var value = state.Evaluate(list[1]);
                    Console.WriteLine(value);
                    return value;
                });
            Expression("print-hex", list => list[1].Type, list => GenerateExpression(list[1]))
                .Interpret((list, state) => {
                    var value = state.Evaluate(list[1]);
                    Console.WriteLine($"0x{value:X}");
                    return value;
                });
        }
    }
}