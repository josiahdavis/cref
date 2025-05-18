import torch

def write(x, file):
    file.write(x.numpy().astype("float32").tobytes())

if __name__ == "__main__":

    B = 2
    T = 3
    C_in = 4
    C_out = 5

    torch.manual_seed(733)
    x = torch.randint(high=5, size=(B, T, C_in))
    Wx = torch.randint(high=5, size=(C_in, C_out))
    out = x @ Wx

    print(f"{x.shape=}, {Wx.shape=}, {out.shape=}")
    print(f"x=\n{x}\n\nWx=\n{Wx}\n\nout=\n{out}")

    with open("matmul.bin", "wb") as file:
        write(x, file)
        write(Wx, file)
        write(out, file)