
#### FAILED: fdfbfa99e1 (ci: work around Debian 12's HTTP/2 authentication failures, 2026-10-25)

Unexpected AI decision: ''. Full output:

```
Error: Authentication token found but could not be validated.

  Failed to fetch PAT user login (401): GitHub returned: Bad credentials
  Failed to fetch GitHub CLI user login (401): GitHub returned: Bad credentials

Your token may still be valid. Check your network connection and try again.

To authenticate, you can use any of the following methods:
  • Start 'copilot' and run the '/login' command
  • Set the COPILOT_GITHUB_TOKEN, GH_TOKEN, or GITHUB_TOKEN environment variable
  • Run 'gh auth login' to authenticate with the GitHub CLI
```

