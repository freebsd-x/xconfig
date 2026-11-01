# xconfig

> **Retired (2026-11-01) — archived, read-only.** `xconfig` was a placeholder: the
> process never ran, never connected to XBus, and the service it named runs
> inside the compositor (`core/xserver`, see
> [xserver](https://github.com/freebsd-x/xserver)). Out-of-process daemons now
> live in `core/xserver/daemons/` and register with the compositor the way
> `xfetch` does.

FreeBSD-X configuration service.

Part of **FreeBSD-X**, a GUI platform for FreeBSD. The full workspace is a
multi-repo project assembled with the [`repo`](https://gerrit.googlesource.com/git-repo)
tool:

```sh
repo init -u https://github.com/freebsd-x/manifest.git
repo sync
```

## License

Released under the MIT License — see [LICENSE](LICENSE).
