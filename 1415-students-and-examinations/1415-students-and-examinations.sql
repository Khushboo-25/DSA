
-- SELECT 
--     t1.student_id, 
--     t1.student_name,
--     t2.subject_name,
--     COUNT(t2.student_id) AS exam_count
-- FROM students t1
-- LEFT JOIN (
--     SELECT 
--         sb.subject_name, 
--         e.student_id 
--     FROM subjects sb 
--     LEFT JOIN examinations e 
--     ON sb.subject_name = e.subject_name
-- ) AS t2 
-- ON t1.student_id = t2.student_id 
-- GROUP BY t1.student_id, t1.student_name, t2.subject_name
-- ORDER BY t1.student_id, t2.subject_name;

SELECT 
    s.student_id,
    s.student_name,
    sb.subject_name,
    COUNT(e.student_id) AS attended_exams
FROM students s
CROSS JOIN subjects sb
LEFT JOIN examinations e 
    ON e.student_id = s.student_id 
    AND e.subject_name = sb.subject_name
GROUP BY s.student_id, s.student_name, sb.subject_name
ORDER BY s.student_id, sb.subject_name;
