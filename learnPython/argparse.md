```
import argparse
parser = argparse.ArgumentParser()

parser.add_argument('--mode', type=str, default='srgan', help='srgan, evaluate')

args = parser.parse_args()
```