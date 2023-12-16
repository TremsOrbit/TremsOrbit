<?php
include 'top.php';
?>


    <section class="I-dont">
        <figure>
            <img id="sunset" class="rounded-image" alt="a sunset in Africa" src="images/sunset.jpg">
            <figcaption>Source: google.com</figcaption>
        </figure>
    </section>  

<main>
        <div class="my-goal">
            <h2><span>My Goal</span></h2>
            <p>My project initially started with photoshop, making a themed environmental awareness poster.  Now, with this website project, I can display my message about wanting to halt the horrible treatment of some of Earth's most magnificent animals.<br>  It's not much right now; but I hope with time that I can evolve this website into something more.</p>
        </div>
        <section class="I-cant">
            <h3><strong><span>Important Information</span></strong></h3>

            <table>
                 <tr>
                    <th>Rhino Species</th>
                    <th>Population</th>
                    <th>The Impacts of Poachers</th>
                </tr>
                    <?php

                $sql = 'SELECT fldSpecies, fldPopulation, fldImpact FROM tblRhinoceros';

                    $statement = $pdo->prepare($sql);
                    $statement->execute();

                    $records = $statement->fetchAll();

                    foreach($records as $record){
                        print '<tr>';
                        print '<td>' . $record['fldSpecies'] . '</td>';
                        print '<td>' . $record['fldPopulation'] . '</td>';
                        print '<td>' . $record['fldImpact'] . '</td>';
                        print '</tr>' . PHP_EOL;
                    }
                    ?>

                <tr>
                    <span><td colspan="3">Source: <cite><a href="https://rhinos.org/our-work/what-we-do/">International Rhino Foundation</a></td></span>
                </tr>
            </table>
        </section>   
</main>
    <?php include 'footer.php'; ?>
</body>

</html>
