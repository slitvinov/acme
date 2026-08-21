import sys, traceback

def hook(t, v, tb):
    if issubclass(t, SyntaxError) and v.filename:
        print(f'{v.filename}:{v.lineno}: {(v.text or "").strip()}', file=sys.stderr)
        print(f'{t.__name__}: {v.msg}', file=sys.stderr)
        return
    for f in traceback.extract_tb(tb):
        print(f'{f.filename}:{f.lineno}: {f.line}', file=sys.stderr)
    print(f'{t.__name__}: {v}', file=sys.stderr)

sys.excepthook = hook
