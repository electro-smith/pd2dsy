# -*- mode: python ; coding: utf-8 -*-


block_cipher = None


a = Analysis(
    ['pd2dsy_gui.py'],
    pathex=[],
    binaries=[],
    datas=[
        ('libdaisy', 'libdaisy'),
        ('examples', 'examples'),
        ('util', 'util'),
        ('vscode_temp', 'vscode_temp'),
        ('LICENSE', '.'),
        ('build/hvcc/hvcc', 'hvcc'),
        ('build/Sun-Valley-ttk-theme/sun-valley.tcl', 'sv_ttk/'),
        ('build/Sun-Valley-ttk-theme/theme', 'sv_ttk/theme'),
        ('build/json2daisy/src/json2daisy', 'json2daisy')
    ],
    hiddenimports=[],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
    noarchive=False,
)
pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

exe = EXE(
    pyz,
    a.scripts,
    [],
    exclude_binaries=True,
    name='pd2dsy_gui',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    console=True,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)
coll = COLLECT(
    exe,
    a.binaries,
    a.zipfiles,
    a.datas,
    strip=False,
    upx=True,
    upx_exclude=[],
    name='pd2dsy_gui',
)
