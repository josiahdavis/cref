import torch

def write(x, file):
    file.write(x.numpy().astype("float32").tobytes())

if __name__ == "__main__":

    B = 16
    C_in = 128
    C_out = 128

    torch.manual_seed(733)
    x = torch.randint(high=500, size=(B, C_in))
    Wx = torch.randint(high=500, size=(C_in, C_out))
    out = x @ Wx

    print(f"{x=}\n\n{Wx=}\n\n{out=}")

    with open("matmul.bin", "wb") as file:
        write(x, file)
        write(Wx, file)
        write(out, file)