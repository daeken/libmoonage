using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using Arch;
using NUnit.Framework;

namespace InterpretedTests {
	public class InsnTest {
		public string Class;
		public uint Instruction;
		public readonly Dictionary<object, dynamic> Preconditions = new Dictionary<object, dynamic>();
		public readonly Dictionary<object, dynamic> Postconditions = new Dictionary<object, dynamic>();

		public void Run() {
			var def = Core.Defs.First(x => x.Name == Class);
			var state = ExecutionState.Cleanroom();
			state.Registers["PC"] = TestGen.PC;
			var locals = state.Locals;
			foreach(var field in def.Fields)
				locals[field.Key] = (Instruction >> field.Value.Shift) & ((1U << field.Value.Bits) - 1);
			state.Evaluate((PTree) def.Decode);
			
			foreach(var (key, value) in Preconditions)
				if(key is ulong page)
					state.Memory[page] = value;
				else
					state.Registers[(string) key] = value;
			
			state.Evaluate((PTree) def.Eval);
			
			foreach(var (key, value) in Postconditions)
				if(key is ulong page)
					Assert.AreEqual(value, state.Memory[page], $"[0x{page << 12:X}]");
				else if(((object) value).GetType().IsConstructedGenericType &&
				        ((object) value).GetType().GetGenericTypeDefinition() == typeof(Vector128<>))
					Assert.AreEqual(value.As<byte>(), state.Registers[(string) key].As<byte>(), (string) key);
				else
					Assert.AreEqual(value, state.Registers[(string) key], (string) key);
		}
	}
	
	[Parallelizable(ParallelScope.All)]
	public class Tests {
		static Vector128<byte> ToVector(string data) =>
			new Vector128<byte>(data.Split(" ").Select(x => byte.Parse(x, NumberStyles.HexNumber)));
		
		[Test]
		public void ADCS() =>
			new InsnTest {
				Class = "ADCS", 
				Instruction = 0xba000000, 
				Preconditions = { ["X0"] = 0x80000000, ["NZCV-C"] = 1 }, 
				Postconditions = { ["X0"] = 0x100000001, ["NZCV-N"] = 0, ["NZCV-Z"] = 0, ["NZCV-C"] = 0, ["NZCV-V"] = 0 }
			}.Run();
		
		[Test]
		public void ADD_extended_register() =>
			new InsnTest {
				Class = "ADD-extended-register",
				Instruction = 0x0b201420,
				Preconditions = {
					["X0"] = 0x80000000, 
					["X1"] = 0x8000000000000000, 
				},
				Postconditions = {
					["X0"] = 0x80000000, 
				}
			}.Run();
		
		[Test]
		public void ADD_shifted_register() =>
			new InsnTest {
				Class = "ADD-shifted-register",
				Instruction = 0x0b00fc02,
				Preconditions = {
					["X0"] = 0x80000000, 
				},
				Postconditions = {
					["X2"] = 0x0, 
				}
			}.Run();
		
		[Test]
		public void ADDS_extended_register() =>
			new InsnTest {
				Class = "ADDS-extended-register",
				Instruction = 0x2b200803,
				Preconditions = {
					["X0"] = 0x80000000, 
				},
				Postconditions = {
					["X3"] = 0x80000000, 
					["NZCV-N"] = 1, 
					["NZCV-Z"] = 0, 
					["NZCV-C"] = 0, 
					["NZCV-V"] = 0, 
				}
			}.Run();
		
		[Test]
		public void ADDS_immediate() =>
			new InsnTest {
				Class = "ADDS-immediate",
				Instruction = 0xb1000002,
				Preconditions = {
					["X0"] = 0xFFFEFFFFFFFFFFFF, 
				},
				Postconditions = {
					["X2"] = 0xFFFEFFFFFFFFFFFF, 
					["NZCV-N"] = 1, 
					["NZCV-Z"] = 0, 
					["NZCV-C"] = 0, 
					["NZCV-V"] = 0, 
				}
			}.Run();

		[Test]
		public void AND_vector() =>
			new InsnTest {
				Class = "AND-vector", 
				Instruction = 0x4e201c00, 
				Preconditions = { ["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0") }, 
				Postconditions = { ["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0") }
			}.Run();

		[Test]
		public void BIC_vector_immediate_16bit() =>
			new InsnTest {
				Class = "BIC-vector-immediate-16bit", 
				Instruction = 0x2f00945f, 
				Preconditions = { ["V31"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0") }, 
				Postconditions = { ["V31"] = ToVector("00 00 00 00 00 C0 5C C0 00 00 00 00 00 00 00 00") }
			}.Run();
		
		[Test]
		public void BIC_vector_immediate_32bit() =>
			new InsnTest {
				Class = "BIC-vector-immediate-32bit",
				Instruction = 0x2f001503,
				Preconditions = {
					["V3"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V3"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void BIC_vector_register() =>
			new InsnTest {
				Class = "BIC-vector-register",
				Instruction = 0x0e611c3f,
				Preconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V31"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void CCMN_immediate() =>
			new InsnTest {
				Class = "CCMN-immediate",
				Instruction = 0xba400800,
				Preconditions = {
					["NZCV-Z"] = 0x1, 
					["X0"] = 0xFFFEFFFFFFFFFFFF, 
				},
				Postconditions = {
					["NZCV-N"] = 1, 
					["NZCV-Z"] = 0, 
					["NZCV-C"] = 0, 
					["NZCV-V"] = 0, 
				}
			}.Run();
		
		[Test]
		public void CCMP_immediate() =>
			new InsnTest {
				Class = "CCMP-immediate",
				Instruction = 0xfa400800,
				Preconditions = {
					["NZCV-Z"] = 0x1, 
					["X0"] = 0x80000000, 
				},
				Postconditions = {
					["NZCV-N"] = 0, 
					["NZCV-Z"] = 0, 
					["NZCV-C"] = 1, 
					["NZCV-V"] = 0, 
				}
			}.Run();
		
		[Test]
		public void CCMP_register() =>
			new InsnTest {
				Class = "CCMP-register",
				Instruction = 0xfa400000,
				Preconditions = {
					["NZCV-Z"] = 0x1, 
					["X0"] = 0x80000000, 
				},
				Postconditions = {
					["NZCV-N"] = 0, 
					["NZCV-Z"] = 1, 
					["NZCV-C"] = 1, 
					["NZCV-V"] = 0, 
				}
			}.Run();

		[Test]
		public void CSINV() =>
			new InsnTest {
				Class = "CSINV", 
				Instruction = 0xda9f0000, 
				Preconditions = { ["NZCV-Z"] = 0 }, 
				Postconditions = { ["X0"] = 0xFFFFFFFFFFFFFFFF }
			}.Run();
		
		[Test]
		public void EXTR() =>
			new InsnTest {
				Class = "EXTR",
				Instruction = 0x13800042,
				Preconditions = {
					["X2"] = 0x80000000, 
					["X0"] = 0x10000, 
				},
				Postconditions = {
					["X2"] = 0x10000, 
				}
			}.Run();
		
		[Test]
		public void FCVTAS_scalar_integer() =>
			new InsnTest {
				Class = "FCVTAS-scalar-integer",
				Instruction = 0x1e2403e0,
				Preconditions = {
					["V31"] = ToVector("01 01 01 01 01 01 01 01 01 01 01 01 01 01 01 01"), 
				},
				Postconditions = {
					["X0"] = 0x0, 
				}
			}.Run();
		
		[Test]
		public void FCVTAU_scalar_integer() =>
			new InsnTest {
				Class = "FCVTAU-scalar-integer",
				Instruction = 0x1e250041,
				Preconditions = {
					["V2"] = ToVector("01 01 01 01 01 01 01 01 01 01 01 01 01 01 01 01"), 
				},
				Postconditions = {
					["X1"] = 0x0, 
				}
			}.Run();
		
		[Test]
		public void FCVTMU_scalar_integer() =>
			new InsnTest {
				Class = "FCVTMU-scalar-integer",
				Instruction = 0x1e710041,
				Preconditions = {
					["V2"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["X1"] = 0x0, 
				}
			}.Run();
		
		[Test]
		public void FCVTPU_scalar_integer() =>
			new InsnTest {
				Class = "FCVTPU-scalar-integer",
				Instruction = 0x9e690002,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["X2"] = 0x0, 
				}
			}.Run();

		[Test]
		public void FMAX_scalar() =>
			new InsnTest {
				Class = "FMAX-scalar", 
				Instruction = 0x1e214be1, 
				Preconditions = {
					["V31"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF"), 
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0")
				}, 
				Postconditions = { ["V1"] = ToVector("FF FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00") }
			}.Run();

		[Test]
		public void FMAXNM_scalar() =>
			new InsnTest {
				Class = "FMAXNM-scalar", 
				Instruction = 0x1e216842, 
				Preconditions = {
					["V2"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
					["V1"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF")
				}, 
				Postconditions = { ["V2"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00") }
			}.Run();

		[Test]
		public void FMIN_scalar() =>
			new InsnTest {
				Class = "FMIN-scalar", 
				Instruction = 0x1e205862, 
				Preconditions = {
					["V3"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF"), 
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0")
				}, 
				Postconditions = { ["V2"] = ToVector("FF FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00") }
			}.Run();

		[Test]
		public void FMINNM_scalar() =>
			new InsnTest {
				Class = "FMINNM-scalar", 
				Instruction = 0x1e21787f, 
				Preconditions = {
					["V3"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
					["V1"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF")
				}, 
				Postconditions = { ["V31"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00") }
			}.Run();

		[Test]
		public void FMLA_by_element_vector_spdp() =>
			new InsnTest {
				Class = "FMLA-by-element-vector-spdp", 
				Instruction = 0x0f811021, 
				Preconditions = { ["V1"] = ToVector("00 00 F6 C2 00 00 F6 C2 00 00 F6 C2 00 00 F6 C2") }, 
				Postconditions = { ["V1"] = ToVector("00 78 6A 46 00 78 6A 46 00 00 00 00 00 00 00 00") }
			}.Run();

		[Test]
		public void FMLA_vector() =>
			new InsnTest {
				Class = "FMLA-vector",
				Instruction = 0x0e21cc21,
				Preconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V1"] = ToVector("00 00 00 00 90 21 0A 41 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FMLS_by_element_vector_spdp() =>
			new InsnTest {
				Class = "FMLS-by-element-vector-spdp",
				Instruction = 0x0f805800,
				Preconditions = {
					["V0"] = ToVector("00 00 F6 C2 00 00 F6 C2 00 00 F6 C2 00 00 F6 C2"), 
				},
				Postconditions = {
					["V0"] = ToVector("00 50 6E C6 00 50 6E C6 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FMLS_vector() =>
			new InsnTest {
				Class = "FMLS-vector",
				Instruction = 0x0ea0cc00,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V0"] = ToVector("00 00 00 00 90 81 79 C1 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FMOV_general() =>
			new InsnTest {
				Class = "FMOV-general",
				Instruction = 0x9eae0000,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["X0"] = 0xC05EC00000000000, 
				}
			}.Run();
		
		[Test]
		public void FMSUB() =>
			new InsnTest {
				Class = "FMSUB",
				Instruction = 0x1f00803f,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
					["V1"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF"), 
				},
				Postconditions = {
					["V31"] = ToVector("FF FF FF 7F 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FMUL_by_element_vector_spdp() =>
			new InsnTest {
				Class = "FMUL-by-element-vector-spdp",
				Instruction = 0x0f80901f,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V31"] = ToVector("00 00 00 00 00 00 00 80 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FNMADD() =>
			new InsnTest {
				Class = "FNMADD",
				Instruction = 0x1f200422,
				Preconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
					["V0"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF"), 
				},
				Postconditions = {
					["V2"] = ToVector("FF FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FNMSUB() =>
			new InsnTest {
				Class = "FNMSUB",
				Instruction = 0x1f20801f,
				Preconditions = {
					["V0"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF"), 
				},
				Postconditions = {
					["V31"] = ToVector("FF FF FF 7F 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FRINTM_scalar() =>
			new InsnTest {
				Class = "FRINTM-scalar",
				Instruction = 0x1e254020,
				Preconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V0"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FRINTP_scalar() =>
			new InsnTest {
				Class = "FRINTP-scalar",
				Instruction = 0x1e24c060,
				Preconditions = {
					["V3"] = ToVector("01 01 01 01 01 01 01 01 01 01 01 01 01 01 01 01"), 
				},
				Postconditions = {
					["V0"] = ToVector("00 00 80 3F 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FRINTZ_scalar() =>
			new InsnTest {
				Class = "FRINTZ-scalar",
				Instruction = 0x1e25c001,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V1"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void FRSQRTE_vector() =>
			new InsnTest {
				Class = "FRSQRTE-vector",
				Instruction = 0x6ee1d803,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V3"] = ToVector("00 00 00 00 00 00 F8 7F 00 00 00 00 00 00 F8 7F"), 
				}
			}.Run();
		
		[Test]
		public void FRSQRTS_vector() =>
			new InsnTest {
				Class = "FRSQRTS-vector",
				Instruction = 0x0ea0fc01,
				Preconditions = {
					["V0"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF"), 
				},
				Postconditions = {
					["V1"] = ToVector("FF FF FF 7F FF FF FF 7F 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void MVNI_vector_32bit_MSL() =>
			new InsnTest {
				Class = "MVNI-vector-32bit-MSL",
				Instruction = 0x2f00e401,
				Postconditions = {
					["V1"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void NEG_vector() =>
			new InsnTest {
				Class = "NEG-vector",
				Instruction = 0x2ea0b801,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V1"] = ToVector("00 00 00 00 00 40 A1 3F 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void ORR_simd_register() =>
			new InsnTest {
				Class = "ORR-simd-register",
				Instruction = 0x0ea01c01,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void PMULL2() =>
			new InsnTest {
				Class = "PMULL[2]",
				Instruction = 0x0ee0e01f,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V31"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 50 54 11 00 50"), 
				}
			}.Run();
		
		[Test]
		public void REV() =>
			new InsnTest {
				Class = "REV",
				Instruction = 0x5ac00800,
				Preconditions = {
					["X0"] = 0x80000000, 
				},
				Postconditions = {
					["X0"] = 0x80, 
				}
			}.Run();
		
		[Test]
		public void REV16() =>
			new InsnTest {
				Class = "REV16",
				Instruction = 0xdac00420,
				Preconditions = {
					["X1"] = 0x80000000, 
				},
				Postconditions = {
					["X0"] = 0x800000, 
				}
			}.Run();
		
		[Test]
		public void SBCS() =>
			new InsnTest {
				Class = "SBCS",
				Instruction = 0xfa000000,
				Preconditions = {
					["X0"] = 0x80000000, 
					["NZCV-C"] = 0x1, 
				},
				Postconditions = {
					["X0"] = 0x0, 
					["NZCV-N"] = 0, 
					["NZCV-Z"] = 1, 
					["NZCV-C"] = 1, 
					["NZCV-V"] = 0, 
				}
			}.Run();
		
		[Test]
		public void SDIV() =>
			new InsnTest {
				Class = "SDIV",
				Instruction = 0x9ac00c23,
				Preconditions = {
					["X0"] = 0x80000000, 
					["X1"] = 0x8000000000000000, 
				},
				Postconditions = {
					["X3"] = 0xFFFFFFFF00000000, 
				}
			}.Run();
		
		[Test]
		public void SHL_vector() =>
			new InsnTest {
				Class = "SHL-vector",
				Instruction = 0x0f08547f,
				Preconditions = {
					["V3"] = ToVector("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF"), 
				},
				Postconditions = {
					["V31"] = ToVector("FF FF FF FF FF FF FF FF 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void SUBS_immediate() =>
			new InsnTest {
				Class = "SUBS-immediate",
				Instruction = 0xf1000000,
				Preconditions = {
					["X0"] = 0x80000000, 
				},
				Postconditions = {
					["NZCV-N"] = 0, 
					["NZCV-Z"] = 0, 
					["NZCV-C"] = 1, 
					["NZCV-V"] = 0, 
				}
			}.Run();
		
		[Test]
		public void UMOV() =>
			new InsnTest {
				Class = "UMOV",
				Instruction = 0x0e1e3c00,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["X0"] = 0xC05E, 
				}
			}.Run();
		
		[Test]
		public void USHL_vector() =>
			new InsnTest {
				Class = "USHL-vector",
				Instruction = 0x2e214423,
				Preconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V3"] = ToVector("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void XTN() =>
			new InsnTest {
				Class = "XTN",
				Instruction = 0x0e612840,
				Preconditions = {
					["V2"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V0"] = ToVector("00 00 00 C0 00 00 00 C0 00 00 00 00 00 00 00 00"), 
				}
			}.Run();
		
		[Test]
		public void XTN2() =>
			new InsnTest {
				Class = "XTN2",
				Instruction = 0x4e212821,
				Preconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V1"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 5E 00 00 00 5E"), 
				}
			}.Run();
		
		[Test]
		public void ZIP() =>
			new InsnTest {
				Class = "ZIP",
				Instruction = 0x4e003800,
				Preconditions = {
					["V0"] = ToVector("00 00 00 00 00 C0 5E C0 00 00 00 00 00 C0 5E C0"), 
				},
				Postconditions = {
					["V0"] = ToVector("00 00 00 00 00 00 00 00 00 00 C0 C0 5E 5E C0 C0"), 
				}
			}.Run();
	}
}