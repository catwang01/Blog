import argparse

parser = argparse.ArgumentParser()

def str2bool(v):
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        raise argparse.ArgumentTypeError('Unsupported value encountered.')

parser.add_argument(
    '--flag',
    type=str2bool,
    nargs='?',
    const=True,
    help='Turn on or turn off flag'
)


args = parser.parse_args()
print(args.flag)

