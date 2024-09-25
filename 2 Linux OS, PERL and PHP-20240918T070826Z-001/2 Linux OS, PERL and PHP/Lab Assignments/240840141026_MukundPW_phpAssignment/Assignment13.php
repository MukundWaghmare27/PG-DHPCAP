<?php
$users = [
    ['username' => 'user1', 'password' => 'pass1'],
    ['username' => 'user2', 'password' => 'pass2'],
    ['username' => 'user3', 'password' => 'pass3'],
    ['username' => 'user4', 'password' => 'pass4'],
    ['username' => 'user5', 'password' => 'pass5'],
];

echo "<html>";
echo "<head><title>User List</title></head>";
echo "<body>";
echo "<h1>User Credentials</h1>";
echo "<table border='1'>";
echo "<tr><th>Username</th><th>Password</th></tr>";

// Iterate through the array and display each user's information
foreach ($users as $user) {
    echo "<tr>";
    echo "<td>" . htmlspecialchars($user['username']) . "</td>";
    echo "<td>" . htmlspecialchars($user['password']) . "</td>";
    echo "</tr>";
}

echo "</table>";
echo "</body>";
echo "</html>";
?>
