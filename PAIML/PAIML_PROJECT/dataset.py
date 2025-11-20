import os
import torch
import pickle
from rdkit import Chem
from torch.utils.data import Dataset
from torch_geometric.data import Data

AA_LIST = list("ACDEFGHIKLMNPQRSTVWY")  # 20 aa
AA2IDX = {a: i+1 for i, a in enumerate(AA_LIST)}  # 0 = PAD

def seq_to_indices(seq, max_len=1000):
    idx = [AA2IDX.get(ch, 0) for ch in seq]
    if len(idx) > max_len:
        idx = idx[:max_len]
    return idx

def load_graph_cache(path):
    if os.path.exists(path):
        with open(path, "rb") as f:
            return pickle.load(f)
    return {}

class DavisDataset(Dataset):
    def __init__(self, csv_path, graph_cache_path="smiles_graphs.pkl", max_protein_len=1000):
        self.df = pd.read_csv(csv_path)
        self.max_protein_len = max_protein_len
        self.graph_cache = load_graph_cache(graph_cache_path)

    def __len__(self):
        return len(self.df)

    def __getitem__(self, idx):
        row = self.df.iloc[idx]
        smi = row["SMILES"]
        prot = row["ProteinSeq"]
        y = float(row["pKd"])

        g = self.graph_cache.get(smi)

        if g is None:  # missing graph
            x = torch.zeros((1,5), dtype=torch.float)
            edge_index = torch.zeros((2,0), dtype=torch.long)
            edge_attr = torch.zeros((0,4), dtype=torch.float)
        else:
            x = torch.tensor(g["atom_feats"], dtype=torch.float)
            edge_index = torch.tensor(g["edge_index"], dtype=torch.long)
            edge_attr = torch.tensor(g["edge_attr"], dtype=torch.float)

        p_idx = seq_to_indices(prot, self.max_protein_len)
        p_idx = torch.tensor(p_idx, dtype=torch.long)

        y = torch.tensor([y], dtype=torch.float)

        data = Data(x=x, edge_index=edge_index, edge_attr=edge_attr, y=y)
        data.protein = p_idx
        return data
