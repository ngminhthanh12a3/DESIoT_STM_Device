## 1.7.0
`12-07-2023`

- Push received bytes to **hGateWayCBuf**;
	- Set up loop handles: **DESIoT_frameFailedHandler**, **DESIoT_frameSuccessHandler**, **DESIoT_frameTimeoutHandler**, **DESIoT_G_frameArbitrating**.
	- Execute successful frame.
	- Check **CMD_SYNC_VIRTUAL_STORAGE**.
	- Execute VSync Weak function.
	- Get payload size.
	- Get VSID.
	- Switch VSID to chose execute function.
	- Declare max size for VSync payload.
	- Use **len** arg to set the payload value.