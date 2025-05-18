import torch

def write(x, file):
    file.write(x.numpy().astype("float32").tobytes())

if __name__ == "__main__":

    B = 2
    C = 3

    torch.manual_seed(733)
    x = torch.randint(high=5, size=(B, C))
    Wx = torch.randint(high=5, size=(C, C))
    out = x @ Wx

    print(f"{x=}\n\n{Wx=}\n\n{out=}")

    with open("matmul.bin", "wb") as file:
        write(x, file)
        write(Wx, file)
        write(out, file)