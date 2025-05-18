import time
import torch

def write(x, file):
    file.write(x.numpy().astype("float32").tobytes())

if __name__ == "__main__":

    B = 64
    C = 512

    torch.manual_seed(733)
    x = torch.rand(size=(B, C))
    Wx = torch.rand(size=(C, C))

    start_time = time.time()
    out = x @ Wx
    print(f"Completed in {time.time() - start_time:.6f} secs")

    with open("matmul.bin", "wb") as file:
        write(x, file)
        write(Wx, file)
        write(out, file)