import torch
import torch.nn as nn
from torchtyping import TensorType

class Solution(nn.Module):
    def __init__(self, vocabulary_size: int):
        super().__init__()
        torch.manual_seed(0)
        self.embed=nn.Embedding(vocabulary_size,16)
        self.linearl=nn.Linear(16,1)
        self.sigmoid=nn.Sigmoid()

    def forward(self, x: TensorType[int]) -> TensorType[float]:
        embeding=self.embed(x)
        average=torch.mean(embeding,dim=1)
        project=self.linearl(average)
        return torch.round(self.sigmoid(project),decimals=4)
