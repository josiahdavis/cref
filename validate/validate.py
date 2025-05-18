import torch

def write(x, file):
    file.write(x.numpy().astype("float32").tobytes())

if __name__ == "__main__":
    size = 10000
    torch.manual_seed(429)
    x = torch.rand(size=(size,)) * 100

    mean = x.mean()
    std = x.std()
    out = (x - mean) / std
    print(f"{out[:5]}, {out.shape=} {mean=:.4f} {std=:.4f}")

    with open("basicstats.bin", "wb") as file:
        write(x, file)
        write(out, file)