<nav class="navbar">
    <a class="<?php
    if ($pathParts['filename'] == "index") {
        print 'activePage';
    }
    ?>" href="index.php">Home Page</a>
    <a class="<?php
    if ($pathParts['filename'] == "detail") {
        print 'activePage';
    }
    ?>" href="detail.php">Information</a>
    <a class="<?php
    if ($pathParts['filename'] == "about") {
        print 'activePage';
    }
    ?>" href="about.php">About the Cause</a>
    <a class="<?php
    if ($pathParts['filename'] == "form") {
        print 'activePage';
    }
    ?>" href="form.php">My Form</a>
    <a class="<?php
    if ($pathParts['filename'] == "array") {
        print 'activePage';
    }
    ?>" href="array.php">Adopt a Rhino!</a>
</nav>