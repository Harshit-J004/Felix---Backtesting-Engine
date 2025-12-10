# Deploy to Team Repo (Safe Mode)
# Creates a new branch 'harshit-submission' to avoid conflicts with existing main

echo "Initializing Git..."
git init

echo "Adding files..."
git add .
git commit -m "Initial 3 days implementation"

echo "Adding Remote..."
git remote add origin https://github.com/joel-bansal/FelixEngine.git

echo "Creating feature branch..."
git checkout -b harshit-submission

echo "Pushing to GitHub..."
git push -u origin harshit-submission

echo "Done! You can now open a Pull Request on GitHub."
